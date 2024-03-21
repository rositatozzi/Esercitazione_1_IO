#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>

double fmaps(double x){
    double a = 1;
    double b = 5;
    double c = -1;
    double d = 2;
    double m = (d-c)/(b-a);
    double q = c-m*a;
    double y = m*x + q;
    return y;
}

int main()
{
    std::string nameFileI = "data.csv";
    std ::ifstream ifstr;
    ifstr.open(nameFileI);
    std::string nameFileO = "result.csv";
    std::ofstream ofstr;
    ofstr.open(nameFileO);

    if(ifstr.fail() ){
        std::cerr << "File input not found" << std::endl;
    }
    if(ofstr.fail() ){
        std::cerr << "File error" << std::endl;
    }
    double val;
    double sum = 0;
    double mean;
    int i = 0;
    ofstr << "# N Mean \n";
    while(ifstr >> val){
        val = fmaps(val);
        sum += val;
        i++;
        mean = sum/i;
        ofstr <<i << " "<< std::scientific << std::setprecision(16)<< mean << "\n";
    }

    ifstr.close();
    ofstr.close();
    return 0;
}
