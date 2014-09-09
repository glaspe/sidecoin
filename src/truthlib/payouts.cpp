/**
 * payouts.cpp
 *
 * Desired logic:
 * 
 *     if new_balance <= old_balance:
 *         output = old_balance - new_balance
 *         change = new_balance
 *     else:
 *         output = 0
 *         change = new_balance
 * 
 * where:
 * 
 *     output -> market address
 *     change -> voter's votecoin address
 * 
 * However, if new_balance > old_balance, then we need more funds than are
 * included in the transaction.
 * 
 * Goal: collect these funds without a central pool.
 *
 * @author Jack Peterson (jack@dyffy.com)
 */

#include "payouts.h"

namespace Payouts {

const int NUM_VOTERS = 10;

VoteTx::VoteTx(int input_value, std::string voter_address)
    : market("")
    , vote("")
    , input_value(input_value)
    , voter_address(voter_address)
    , output(0)
    , change(0)
    , spent(false)
{
}

int VoteTx::get_input_value() { return input_value; }

std::string VoteTx::get_voter_address() { return voter_address; }

void VoteTx::complete()
{
    final_balance[voter_address] += change;
    spent = true;
}

// Pretend consensus algo output.  New balances should match these values.
// Total number of coins is conserved.
std::map<std::string, int> consensus(std::vector<VoteTx> vote_tx_block)
{
    std::map<std::string, int> consensus_output;
    consensus_output["VOTE-0"] = 4;
    consensus_output["VOTE-1"] = 1;
    consensus_output["VOTE-2"] = 13;
    consensus_output["VOTE-3"] = 4;
    consensus_output["VOTE-4"] = 24;
    consensus_output["VOTE-5"] = 4;
    consensus_output["VOTE-6"] = 6;
    consensus_output["VOTE-7"] = 2;
    consensus_output["VOTE-8"] = 1;
    consensus_output["VOTE-9"] = 52;
    return consensus_output;
}

// Decentralized payouts
void payout(std::vector<VoteTx> vote_tx_block)
{
    int old_balance;
    int new_balance;
    int amount_won;
    int amount_lost;
    VoteTx * tx;
    VoteTx * win_tx;
    VoteTx * lose_tx;

    std::map<std::string, int> new_balances = consensus(vote_tx_block);

    // Traverse the vote transaction block and see who won and who lost.
    int winners[NUM_VOTERS];
    int losers[NUM_VOTERS];
    std::cout << "Initial:  ";
    for (int i = 0; i < NUM_VOTERS; ++i)
    {
        tx = &vote_tx_block[i];

        old_balance = tx->get_input_value();
        new_balance = new_balances[tx->get_voter_address()];
        
        std::cout << old_balance << "\t";
        // std::cout << tx->get_voter_address() << ": " << old_balance
        //           << " -> " << new_balance << std::endl;
        
        if (new_balance == old_balance)
        {
            tx->output = 0;
            tx->change += old_balance;
            winners[i] = 0;
            losers[i] = 0;
        }
        else if (new_balance < old_balance)
        {
            tx->output = old_balance - new_balance;
            tx->change += new_balance;
            winners[i] = 0;
            losers[i] = tx->output;
        }
        else
        {
            tx->output = 0;
            tx->change += old_balance;
            winners[i] = new_balance - old_balance;
            losers[i] = 0;
        }
    }
    std::cout << std::endl;

    // Losing/neutral voters' transactions tabulated.
    // Now, distribute their unspent outputs to the winners.
    for (int j = 0; j < NUM_VOTERS; ++j)
    {
        amount_won = winners[j];
        if (amount_won == 0) continue;
        win_tx = &vote_tx_block[j];
        if (win_tx->spent) continue;
        for (int i = 0; i < NUM_VOTERS; ++i)
        {
            if (i == j) continue;
            amount_lost = losers[i];
            if (amount_lost == 0) continue;
            lose_tx = &vote_tx_block[i];
            if (lose_tx->output > 0)
            {
                // Losing UTXO is greater than the winner's payout.
                // Send the full winner's payout amount from loser's output.
                if (lose_tx->output > amount_won)
                {
                    // std::cout << i << " " << lose_tx->output << " " << amount_won
                    //           << " -> " << j << std::endl;
                    lose_tx->output -= amount_won;
                    win_tx->change += amount_won;
                    amount_won = 0;
                }

                // Losing UTXO is smaller than the winner's payout.
                // Send loser's output to the winner.
                else
                {
                    // std::cout << i << " " << lose_tx->output << " " << amount_lost
                    //           << " -> " << j << std::endl;
                    lose_tx->output -= amount_lost;
                    win_tx->change += amount_lost;
                    amount_won -= amount_lost;
                }

                // If the winner's payout is fully accounted for, complete
                // the transaction and move on to the next.
                if (amount_won == 0) {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < NUM_VOTERS; ++i)
        vote_tx_block[i].complete();
}

} // namespace

int main(int argc, char **argv)
{
    std::vector<Payouts::VoteTx> vote_tx_block;
    std::map<std::string, int> consensus_output;

    vote_tx_block.push_back(Payouts::VoteTx(11, "VOTE-0"));
    vote_tx_block.push_back(Payouts::VoteTx(23, "VOTE-1"));
    vote_tx_block.push_back(Payouts::VoteTx(29, "VOTE-2"));
    vote_tx_block.push_back(Payouts::VoteTx(42, "VOTE-3"));
    vote_tx_block.push_back(Payouts::VoteTx(1, "VOTE-4"));
    vote_tx_block.push_back(Payouts::VoteTx(1, "VOTE-5"));
    vote_tx_block.push_back(Payouts::VoteTx(1, "VOTE-6"));
    vote_tx_block.push_back(Payouts::VoteTx(1, "VOTE-7"));
    vote_tx_block.push_back(Payouts::VoteTx(1, "VOTE-8"));
    vote_tx_block.push_back(Payouts::VoteTx(1, "VOTE-9"));

    Payouts::final_balance["VOTE-0"] = 0;
    Payouts::final_balance["VOTE-1"] = 0;
    Payouts::final_balance["VOTE-2"] = 0;
    Payouts::final_balance["VOTE-3"] = 0;
    Payouts::final_balance["VOTE-4"] = 0;
    Payouts::final_balance["VOTE-5"] = 0;
    Payouts::final_balance["VOTE-6"] = 0;
    Payouts::final_balance["VOTE-7"] = 0;
    Payouts::final_balance["VOTE-8"] = 0;
    Payouts::final_balance["VOTE-9"] = 0;

    Payouts::payout(vote_tx_block);

    // Quick-and-dirty testing
    consensus_output = Payouts::consensus(vote_tx_block);
    std::map<std::string, int>::iterator c, end;
    std::cout << "Expected: ";
    for (c = consensus_output.begin(), end = consensus_output.end(); c != end; ++c)
        std::cout << c->second << "\t";
    std::cout << std::endl;
    std::cout << "Actual:   ";
    for (c = Payouts::final_balance.begin(), end = Payouts::final_balance.end();
         c != end; ++c)
        std::cout << c->second << "\t";
    std::cout << std::endl;
    if (consensus_output == Payouts::final_balance)
        std::cout << "Success!" << std::endl;
    else
        std::cout << "Fail" << std::endl;

    return 0;
}
