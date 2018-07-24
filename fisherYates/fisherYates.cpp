#include <vector>
#include <random>
#include <iostream>
#include <cmath>

class FisherYates {
    private:
        std::vector<int> my_vector;

    public:
        FisherYates(const std::vector<int> &v1) {
            my_vector = v1;
        }
        
        std::vector<int> getVector() const {
            return my_vector;
        }

        void shuffle() {
            int tmp;
            int random_index;
            std::random_device rd;
            std::default_random_engine generator(rd());
            std::uniform_real_distribution<double> distribution(0.0, 1.0);
            for(int i = my_vector.size() - 1; i > 0; i--) {
                random_index = std::floor(distribution(generator)*(i+1));
                tmp = my_vector[i];
                my_vector[i] = my_vector[random_index];
                my_vector[random_index] = tmp;
            }

        }

        void printVector() const {
            std::cout << "[";
            std::cout << my_vector[0]; 
            for(int i = 1; i < my_vector.size(); i++) {
                std::cout << ", " << my_vector[i];   
            }
            std::cout << "]\n";
        }       
};

int main() {
    std::cout << "Starting Unit Test of the FisherYates class\n";
    std::vector<int> my_vector = {1, 2, 3, 4, 5};
    std::cout << "Constructing class using {1, 2, 3, 4, 5} vector as argument\n";
    FisherYates my_fisher_yates(my_vector);

    std::cout << "Printing unshuffled vector\n";
    my_fisher_yates.printVector();
    std::cout << "\n";
           
    std::cout << "Shuffling vector\n";
    my_fisher_yates.shuffle();
    std::cout << "Printing shuffled vector\n";
    my_fisher_yates.printVector();
    std::cout << "\n";

    std::vector<int> histogram = {0, 0, 0, 0, 0};
    std::cout << "Watching the positions where the number 1 ends up after ten thousand shuffles\n";
    for(int i = 0; i < 10000; i++) {
        my_fisher_yates.shuffle();
        my_vector = my_fisher_yates.getVector();
        for(int j = 0; j < my_vector.size(); j++){
            if(my_vector[j] == 1) {
                histogram[j]++;
                break;
            }
        }
    }

    std::cout << "1st position: " << histogram[0] << " times\n" <<
                "2nd posittion: " << histogram[1] << " times\n" <<
                "3rd position: " << histogram[2] << " times\n" <<
                "4rd position: " << histogram[3] << " times\n" <<
                "5th position: " << histogram[4] << " times\n";
    return 0;
}
 
