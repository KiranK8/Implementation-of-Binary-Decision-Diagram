#include <iostream>
#include "ManagerInterface.h"
using namespace std;

typedef int BDD_ID;
//struct table{
//    string node;
//    BDD_ID iID, iHigh, iLow, iTopVar;
//}BDD_table[5];
//
//
//int GL_Top;

const BDD_ID &False(){
    BDD_table[0].node = "False";
    BDD_table[0].iID = 0;
    BDD_table[0].iHigh = 0;
    BDD_table[0].iLow = 0;
    BDD_table[0].iTopVar = 0;

    GL_Top = BDD_table[0].iID;
    return BDD_table[0].iID;
};

const BDD_ID &True(){
    BDD_table[1].node = "True";
    BDD_table[1].iID = 1;
    BDD_table[1].iHigh = 1;
    BDD_table[1].iLow = 1;
    BDD_table[1].iTopVar = 1;

    GL_Top = BDD_table[1].iID;
    return BDD_table[1].iID;
};
BDD_ID createVar(const std::string &label){
    GL_Top++;
    BDD_table[GL_Top].node = label;
    BDD_table[GL_Top].iID = GL_Top;

    return BDD_table[GL_Top].iID;

};

BDD_ID topVar(const BDD_ID f){
    return BDD_table[f].iTopVar;
};

BDD_ID ite(const BDD_ID i, const BDD_ID t, const BDD_ID e){

}

BDD_ID neg(const BDD_ID a){
    BDD_ID temp;
    temp = ite(a, 0, 1);
    return temp;
};

BDD_ID and2(const BDD_ID a, const BDD_ID b){
    BDD_ID temp;
    temp = ite(a, b, 0);
    return temp;
};

BDD_ID or2(const BDD_ID a, const BDD_ID b){
    BDD_ID temp;
    temp = ite(a, 1, b);
    return temp;
};

BDD_ID xor2(const BDD_ID a, const BDD_ID b){
    BDD_ID temp;
    temp = ite(a, !b, b);
    return temp;
};

BDD_ID nand2(const BDD_ID a, const BDD_ID b){
    BDD_ID temp;
    temp = ite(!a, 1, !b);
    return temp;
};

BDD_ID nor2(const BDD_ID a, const BDD_ID b){
    BDD_ID temp;
    temp = ite(!a, !b, 0);
    return temp;
};

BDD_ID xnor2(const BDD_ID a, const BDD_ID b){
    BDD_ID temp;
    temp = ite(a, b, !b);
    return temp;
};

std::string getTopVarName(const BDD_ID &root){
    BDD_ID temp;
    temp = BDD_table[root].iTopVar;
    return BDD_table[temp].node;
}


int main() {
    BDD_ID x,y,z,b,p,q,r,s;
//    x = False();
////    std::cout << "i is " <<  i << endl;
//    std::cout << BDD_table[0].node << x << BDD_table[0].iHigh << BDD_table[0].iLow << BDD_table[0].iTopVar << std::endl;
//    std::cout << "Global Top Variable is " <<  GL_Top << endl;
//    y = True();
////    std::cout << "i is " <<  i << endl;
//    std::cout << BDD_table[1].node << y << BDD_table[1].iHigh << BDD_table[1].iLow << BDD_table[1].iTopVar << std::endl;
//    std::cout << "Global Top Variable is " <<  GL_Top << endl;
//
//    z = createVar("a");
//    std::cout << BDD_table[GL_Top].node << z << std::endl;
//    std::cout << "Global Top Variable is " <<  GL_Top << endl;
//
//    b = createVar("b");
//    std::cout << BDD_table[GL_Top].node << b << std::endl;
//    std::cout << "Global Top Variable is " <<  GL_Top << endl;
//
//    p = createVar("p");
//    std::cout << BDD_table[GL_Top].node << p << std::endl;
//    std::cout << "Global Top Variable is " <<  GL_Top << endl;
//
//    q = topVar(1);
//    std::cout <<"Top variable is "<< q << std::endl;

    return 0;


}
