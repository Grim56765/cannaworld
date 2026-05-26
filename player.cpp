#include "plant.cpp"

int plant() {
    Genotype clemmonsGeno;

    std::cout << "=== Clemmons Genetic Line ===\n\n";

    for (int i = 0; i < 5; i++) {
        Phenotype pheno(clemmonsGeno);

        std::cout << "Plant " << (i + 1) << "\n";
        std::cout << pheno.phenoGrowthSpeed << " Weeks\n";
        std::cout << pheno.phenoYield << " Ounces\n";
        std::cout << "Color: " << pheno.color << "\n";
        std::cout << "Hidden Color: " << pheno.hiddenColor << "\n";
        std::cout << pheno.colorExpressed << "\n";
        std::cout << pheno.gender << "\n\n";
    }
}