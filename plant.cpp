#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <sstream>
#include <algorithm>

int clamp(int value) {
    return std::max(0, std::min(255, value));
}

std::string rgb_to_hex(int r, int g, int b) {
    std::stringstream ss;
    ss << std::uppercase << "#" << std::hex << std::setw(2) << std::setfill('0') << r
       << std::setw(2) << std::setfill('0') << g
       << std::setw(2) << std::setfill('0') << b;
    return ss.str();
}

class Genotype {
public:
    int gS_lower;
    int gS_higher;
    int y_lower;
    int y_higher;
    int hiddenRedBias;
    int hiddenGreenBias;
    int hiddenBlueBias;

    Genotype() {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> dist_gs_low(8, 12);
        gS_lower = dist_gs_low(gen);

        std::uniform_int_distribution<> dist_gs_high(13, 20);
        gS_higher = dist_gs_high(gen);

        std::uniform_int_distribution<> dist_y_low(8, 32);
        y_lower = dist_y_low(gen);

        std::uniform_int_distribution<> dist_y_high(33, 48);
        y_higher = dist_y_high(gen);

        std::uniform_int_distribution<> dist_col(0, 255);
        hiddenRedBias = dist_col(gen);
        hiddenGreenBias = dist_col(gen);
        hiddenBlueBias = dist_col(gen);
    }
};

class Phenotype {
public:
    int phenoGrowthSpeed;
    int phenoYield;
    std::string color;
    std::string hiddenColor;
    std::string colorExpressed;
    int expressionStrength;
    std::string gender;

    Phenotype(const Genotype& geno) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> dist_gs(geno.gS_lower, geno.gS_higher);
        phenoGrowthSpeed = dist_gs(gen);

        std::uniform_int_distribution<> dist_y(geno.y_lower, geno.y_higher);
        phenoYield = dist_y(gen);

        // === Color logic (matches your Python version) ===
        int baseR = 50;
        int baseG = 100;
        int baseB = 50;

        std::uniform_int_distribution<> dist_var(-25, 25);
        int variation = dist_var(gen);

        int r = clamp(geno.hiddenRedBias + variation);
        int g = clamp(geno.hiddenGreenBias + variation);
        int b = clamp(geno.hiddenBlueBias + variation);

        color = rgb_to_hex(baseR, baseG, baseB);           // Visible base color
        hiddenColor = rgb_to_hex(r, g, b);                 // Hidden genetic color

        std::uniform_int_distribution<> dist_expr(1, 10);
        expressionStrength = dist_expr(gen);

        std::uniform_int_distribution<> dist_chance(1, 100);
        int colorChancePercent = dist_chance(gen);

        if (colorChancePercent <= 20) {
            colorExpressed = "Color is expressed (strength: " + std::to_string(expressionStrength) + ")";
        } else {
            colorExpressed = "Color is not expressed";
        }

        // === Gender ===
        std::uniform_int_distribution<> dist_gender(1, 100);
        int gend = dist_gender(gen);
        gender = (gend > 51) ? "M" : "F";
    }
};

int main() {
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

    return 0;
}
