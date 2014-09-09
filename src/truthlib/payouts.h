#ifndef __PAYOUTS_H_INCLUDED__
#define __PAYOUTS_H_INCLUDED__

#include <map>
#include <string>
#include <vector>
#include <iostream>

namespace Payouts {

extern const int NUM_VOTERS;
std::map<std::string, int> final_balance;

class VoteTx
{
private:
    std::string market;
    std::string vote;
    int input_value;
    std::string voter_address;
public:
    VoteTx(int, std::string);
    int output;
    int change;
    bool spent;
    int get_input_value();
    std::string get_voter_address();
    void complete();
};

std::map<std::string, int> consensus(std::vector<VoteTx>);
void payout(std::vector<VoteTx>);

}

#endif
