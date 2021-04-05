#include "Board.hpp"
#include <iostream>
using ariel::Direction;
using namespace std;
using namespace ariel;

namespace ariel{ 

Board::Board(){}
void Board::post(unsigned int width,unsigned int length,ariel::Direction x, string m_s){
    switch(x){
        case Direction::Horizontal:
        for(size_t i=0; i<m_s.length();i++){
            umap[width][length+i]=m_s[i];
        }
        return;

        case Direction::Vertical:
        for(size_t i=0; i<m_s.length();i++){
            umap[width+i][length]=m_s[i];
        }
        return;

        default:
        return;
    }
};

string Board::read(unsigned int width,unsigned int length,ariel::Direction y,unsigned int num_of_lettters){
    string temp;
    switch(y){
        case Direction::Horizontal:

        for(size_t i=0; i<num_of_lettters;i++){
           if((!umap[width].empty())&&(umap[width][length+i])){
              
               temp+=umap[width][length+i];
               }
           else{
                   temp+="_";
               }
        }
        return temp;
        

        case Direction::Vertical:
        for(size_t i=0; i<num_of_lettters;i++){
           if((!umap[width+i].empty())&&(umap[width+i][length])){

               temp+=umap[width+i][length];
               
           }
           else{
                   temp+="_";
               }
        }
        return temp;

        default:
        return "eror";
    }
    
};
string Board::show(){return "_";};

Board::~Board(){};

}
