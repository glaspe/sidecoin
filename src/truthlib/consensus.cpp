#include "consensus.h"

namespace Consensus {

SVDOutput test_svd()
{
    SVDOutput output;

    itpp::mat A = "1.0 2.0; 3.0 4.0";
    itpp::mat B = "0.0 1.0; 1.0 0.0";
    itpp::mat C = A*B + 2*A;

    std::cout << "C =\n" << C << std::endl;

    itpp::svd(C, output.U, output.s, output.V);

    output.S = itpp::diag(output.s);
    output.S.set_size(output.U.rows(), output.S.cols(), true);

    return output;
}

} // Consensus

int main()
{
    itpp::mat C;
    Consensus::SVDOutput output;

    output = Consensus::test_svd();

    std::cout << "U =\n" << output.U << std::endl;
    std::cout << "s =\n" << output.s << std::endl;
    std::cout << "V =\n" << output.V << std::endl;
    std::cout << "S =\n" << output.S << std::endl;

    return 0;
}

