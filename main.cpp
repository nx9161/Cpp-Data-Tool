#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

class DataAnalyzer {
private:
    std::vector<double> dataset;

public:
    DataAnalyzer(std::vector<double> data) : dataset(data) {}

    double calculateMean() {
        double sum = std::accumulate(dataset.begin(), dataset.end(), 0.0);
        return sum / dataset.size();
    }

    double calculateMedian() {
        std::sort(dataset.begin(), dataset.end());
        size_t size = dataset.size();
        if (size % 2 == 0) {
            return (dataset[size / 2 - 1] + dataset[size / 2]) / 2;
        } else {
            return dataset[size / 2];
        }
    }

    void displayResults() {
        std::cout << "--- Data Science Tool Analysis ---" << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Mean Value:   " << calculateMean() << std::endl;
        std::cout << "Median Value: " << calculateMedian() << std::endl;
    }
};

int main() {
    // Example dataset: Performance metrics or grades
    std::vector<double> sampleData = {92.5, 88.0, 76.5, 94.0, 85.5, 99.0, 72.0};
    
    DataAnalyzer analyzer(sampleData);
    analyzer.displayResults();

    return 0;
}