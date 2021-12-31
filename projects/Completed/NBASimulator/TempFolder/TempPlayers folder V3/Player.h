#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player{
    public:
        Player();
        
        void setName(string name);
        void setFg(double fg);
        void setRebounds(double rebounds);
        void setAssists(double assists);
        void setSteals(double steals);
        void setBlocks(double blocks);
        void setPoints(double points);
        void setAllNba(int AllNba);
        void setAllNbaSecond(int a);
        void setAllNbaThird(int a);
        void setAllDefense(int a);
        void setAllDefenseSecond(int a);
        void setAllDefenseThird(int a);
        void setAllStarMVP(int a);
        void setROTY(int a);
        void setDPOY(int a);
        void setSMOTY(int a);
        void setTMOTY(int a);
        void setScoringTitle(int a);
        void setFMVP(int a);
        void setMVP(int a);
        void setPlayerWorth(double playerWorth);
        void setTeam(string a);
        void setYearsPro(int a);
        
        string getName() const;
        double getFg() const;
        double getAssists() const;
        double getRebounds() const;
        double getBlocks() const;
        double getSteals() const;
        double getPoints() const;
        int getAllNba() const;
        int getAllNbaSecond() const;
        int getAllNbaThird() const;
        int getAllNbaDefense() const;
        int getAllNbaDefenseSecond() const;
        int getAllNbaDefenseThird() const;
        int getAllStarMVP() const;
        int getROTY() const;
        int getDPOY() const;
        int getSMOTY() const;
        int getTMOTY() const;
        int getScoringTitle() const;
        int getFMVP() const;
        int getMVP() const;
        double getPlayerWorth() const;
        string getTeam() const;
        int getYearsPro() const;
        
        
        
    private:
        
        string team;
        string name;
        double fg;
        double rebounds;
        double assists;
        double steals;
        double blocks;
        double points;
        int AllNba;
        int AllNbaSecond;
        int AllNbaThird;
        int AllDefense;
        int AllDefenseSecond;
        int AllDefenseThird;
        int AllStarMVP;
        int ROTY;
        int DPOY;
        int SMOTY;
        int TMOTY;
        int ScoringTitle;
        int FMVP;
        int MVP;
        double playerWorth;
        int YearsPro;
};
#endif