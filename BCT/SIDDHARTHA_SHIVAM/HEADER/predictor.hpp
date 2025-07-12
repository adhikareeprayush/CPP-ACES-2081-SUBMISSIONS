#pragma once


#include "functions.hpp"



class word_map{
    private:
        std::string word;
        double chance=0;

    public:
    word_map(std::string word,double chance){
        this->word=word;
        this->chance= chance;
        return;
    }

    void set_chance(double chance){
        this->chance=chance;
        return;
    }


    void set_word(std::string word){
        this->word=word;
        return;
    }

    inline double get_chance(){
        return this->chance;
    }

    inline std::string get_word(){
        return this->word;
    }

    void set(std::string word, double chance){
        this->word=word;
        this->chance=chance;
        return;
    }

    word_map* get(){
        return this; 
    }
};

class dictionary{

    private:
    std::vector<word_map> map_vector;

    public:
    dictionary(){
        std::ifstream file(file::source);

        if(!file.is_open()){
            std::cout<<":( no source file found for dictionary "<<std::endl;
            return;
        }


        std::string word;
        while(file>>word){
            word_map wm(word,0);

            this->map_vector.push_back(wm);

        }

        file.close();

        return;
    }



    std::string get_closest_word(std::string word){

        word_map result("",0);

        for(word_map wm: this->map_vector){
            double probability= get_probability(word,wm.get_word());

            if(probability>=result.get_chance()){
                result.set(wm.get_word(),probability);
            }
        }

        return result.get_word();
    }
        



};

//public dictionary dict for performance;
class dictionary dict;