#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player(){
    
}

void Player::setName(string name){
    this->name = name;
}

void Player::setFg(double fg){
    this->fg = fg;
}

void Player::setRebounds(double rebounds){
    this->rebounds = rebounds;
}

void Player::setAssists(double assists){
    this->assists = assists;
}

void Player::setSteals(double steals){
    this->steals = steals;
}

void Player::setPoints(double points){
    this->points = points;
}

void Player::setAllNba(int AllNba){
    this->AllNba = AllNba;
}

void Player::setAllNbaSecond(int AllNbaSecond){
    this->AllNbaSecond = AllNbaSecond;
}

void Player::setAllNbaThird(int AllNbaThird){
    this->AllNbaThird = AllNbaThird;
}

void Player::setAllDefense(int AllDefense){
    this->AllDefense = AllDefense;
}

void Player::setAllDefenseSecond(int AllDefenseSecond){
    this->AllDefenseSecond = AllDefenseSecond;
}

void Player::setAllDefenseThird(int AllDefenseThird){
    this->AllDefenseThird = AllDefenseThird;
}

void Player::setAllStarMVP(int a){
    this->AllStarMVP = a;
}

void Player::setROTY(int a){
    this->ROTY = a;
}

void Player::setDPOY(int a){
    this->DPOY = a;
}

void Player::setSMOTY(int a){
    this->SMOTY = a;
}

void Player::setTMOTY(int a){
    this->TMOTY = a;
}

void Player::setScoringTitle(int a){
    this->ScoringTitle = a;
}

void Player::setFMVP(int a){
    this->FMVP = a;
}

void Player::setMVP(int a){
    this->MVP = a;
}

string Player::getName() const{
    return name;
}

double Player::getFg() const{
    return fg;
}

void Player::setBlocks(double blocks){
    this->blocks = blocks;
}

double Player::getBlocks() const{
    return blocks;
}

double Player::getAssists() const{
    return assists;
}

double Player::getRebounds() const{
    return rebounds;
}

double Player::getSteals() const{
    return steals;
}

double Player::getPoints() const{
    return points;
}

int Player::getAllNba() const{
    return AllNba;
}

int Player::getAllNbaSecond() const{
    return AllNbaSecond;
}

int Player::getAllNbaThird() const{
    return AllNbaThird;
}

int Player::getAllNbaDefense() const{
    return AllDefense;
}

int Player::getAllNbaDefenseSecond() const{
    return AllDefenseSecond;
}

int Player::getAllNbaDefenseThird() const{
    return AllDefenseThird;
}

int Player::getAllStarMVP() const{
    return AllStarMVP;
}

int Player::getROTY() const{
    return ROTY;
}

int Player::getDPOY() const{
    return DPOY;
}

int Player::getSMOTY() const{
    return SMOTY;
}

int Player::getTMOTY() const{
    return TMOTY;
}

int Player::getScoringTitle() const{
    return ScoringTitle;
}

int Player::getFMVP() const{
    return FMVP;
}

int Player::getMVP() const{
    return MVP;
}

void Player::setPlayerWorth(double playerWorth){
    this->playerWorth = playerWorth;
}

double Player::getPlayerWorth() const{
    return playerWorth;
}

string Player::getTeam() const{
    return "why";
}

void Player::setTeam(string a){
    this->team = "string";
}

int Player::getYearsPro() const{
    return YearsPro;
}

void Player::setYearsPro(int a){
    this->YearsPro = a;
}