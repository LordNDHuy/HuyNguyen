#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

typedef struct{
    float a,b;
} dataPoint;

enum trn_params {num_iterations, learning_rate, start_a, start_b, num_folds};

int main()
{
    string str;
    float params[5];
    vector<dataPoint> point_set;
    int k = 0;
    for (int i = 0 ;i < 12 ;i++ ){
        getline(cin, str);
        if (i > 2 && i <  8) {
            string tempstr;
            stringstream ss(str);
            ss >> tempstr >> params[k];
            k++;
        }
    }
    do {
            dataPoint temp;
                stringstream ss(str);
                ss >> temp.a >> temp.b ;
                point_set.push_back(temp);

            }while(getline(cin, str));


        //calculata a b
    int initpoint = 0, termpoint = 0 ;//termpoint = point_set.size()/params[4];
    for(int i = 0;  i < params[num_folds];i++){
            initpoint = termpoint;
            if (i == (params[num_folds] - 1)) {
                termpoint = point_set.size();
            }else  termpoint += point_set.size()/params[num_folds];
            vector<dataPoint> TST, TRN;
            for(int j= initpoint; j < termpoint; j++){
                TST.push_back(point_set[j]);
            }
            TRN = point_set;
            TRN.erase(TRN.begin()+ initpoint, TRN.begin() + termpoint);
            //initpoint = termpoint;
            /*
            if (i == (params[num_folds] - 2)) {
                termpoint = point_set.size();
            }else  termpoint += point_set.size()/params[num_folds];*/

            cout << TST.size()<< " - "<< TRN.size()<<" - "<< point_set.size()<< endl;
            dataPoint P = {params[start_a], params[start_b]};
            float alpha = params[learning_rate];
            for(int j = 0; j < params[num_iterations];j++){
                float derA = 0.0f, derB = 0.0f;
                float y ;
                for(int k = 0; k < TRN.size(); k++){
                    y = P.a*TRN[k].a + P.b;
                    derA += (y - TRN[k].b)*TRN[k].a;
                    derB += (y - TRN[k].b);
                }
                float Glength =sqrt(derA*derA + derB*derB);
                dataPoint G ={derA/Glength, derB/Glength};
                P = {P.a - alpha*G.a, P.b - alpha*G.b};
            }
            //average error
            float average_error = 0.0f;
            for (int i = 0 ; i < TST.size(); i++){
                average_error +=pow(P.a*TST[i].a + P.b - TST[i].b, 2);
            }
            average_error = sqrt(average_error/TST.size());

            //histogram of error
            float e[TST.size()], e_average = 0.0f; // error of histogram
            float y;
            for (int j = 0; j < TST.size(); j++){
                y = P.a*TST[j].a + P.b;
                e[j] = (y - TST[j].b);
                e_average +=e[j];
            }
            e_average = e_average/TST.size();
            cout << "e_average: "<<e_average<< endl;
            //calculate the variance
            float variance = 0.0f;
            for (int j = 0; j < TST.size(); j++){
                variance += pow(e[j] - e_average, 2);
            }

            variance = sqrt(variance/TST.size());
            cout << "variance: "<<variance<< endl;
            //Bound of error
            float Vmin = e_average - 3*variance, Vmax = e_average + 3*variance;
            float V_V[11] , subinterval; // the splitted interval [Vmin,Vmax], subinterval =Vmax - Vmin)/10;
            subinterval = (Vmax - Vmin)/10;
            for(int j = 0; j <= 10; j++){
                float temp = j*subinterval;
                V_V[j] =Vmin + temp;
            }
            cout << P.a << "  "<< P.b<< "  "<< average_error << "  ";

            //histogram
            float histogram[10] = {0,0,0,0,0,0,0,0,0,0};
            int allelement= 0;
            for( int j = 0 ; j < 10; j++){//sub check
                //cout << "["<<V_V[j]<< ","<<V_V[j+1]<<")"<<": ";
                for(int k = 0; k < TST.size(); k++){// error value check
                    if (((e[k] - V_V[j]) >= 10e-10) && ((e[k]) - V_V[j + 1]) < -10e-10  ){
                        histogram[j]++;
                        //cout <<setw(10)<<e[k] << ",   ";
                    }

                }
                allelement+=histogram[j];

                //cout << endl<<endl;


            }//for( int j = 0 ; j < 10; j)
            for(int k = 0; k < 10; k++){

                histogram[k] = histogram[k]/allelement;
                sum+= histogram[k];
                cout << histogram[k]<< "   ";
            }

            //normalize histogram

            cout << endl;
    }//for(int i = 0;  i < params[num_folds];i++)

}

