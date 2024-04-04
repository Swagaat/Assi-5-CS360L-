#include <iostream>
#include <string>

using namespace std;

// Base class Package
class Package {
protected:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZIP;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZIP;
    double weight; // in ounces
    double costPerOunce; // cost per ounce in dollars

public:
    // Constructor
    Package(const string &senderName, const string &senderAddress, const string &senderCity, const string &senderState, const string &senderZIP,
            const string &recipientName, const string &recipientAddress, const string &recipientCity, const string &recipientState, const string &recipientZIP,
            double weight, double costPerOunce)
            : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity), senderState(senderState), senderZIP(senderZIP),
              recipientName(recipientName), recipientAddress(recipientAddress), recipientCity(recipientCity), recipientState(recipientState), recipientZIP(recipientZIP),
              weight(weight), costPerOunce(costPerOunce) {
        if (weight <= 0 || costPerOunce <= 0) {
            cerr << "Error: Weight and cost per ounce must be positive values." << endl;
            exit(1);
        }
    }

    // Calculate shipping cost
    double calculateCost() const {
        return weight * costPerOunce;
    }
};

// Derived class TwoDayPackage
class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    // Constructor
    TwoDayPackage(const string &senderName, const string &senderAddress, const string &senderCity, const string &senderState, const string &senderZIP,
                  const string &recipientName, const string &recipientAddress, const string &recipientCity, const string &recipientState, const string &recipientZIP,
                  double weight, double costPerOunce, double flatFee)
            : Package(senderName, senderAddress, senderCity, senderState, senderZIP,
                      recipientName, recipientAddress, recipientCity, recipientState, recipientZIP,
                      weight, costPerOunce), flatFee(flatFee) {}

    // Calculate shipping cost including flat fee
    double calculateCost() const {
        return Package::calculateCost() + flatFee;
    }
};

// Derived class OvernightPackage
class OvernightPackage : public Package {
private:
    double additionalFeePerOunce;

public:
    // Constructor
    OvernightPackage(const string &senderName, const string &senderAddress, const string &senderCity, const string &senderState, const string &senderZIP,
                     const string &recipientName, const string &recipientAddress, const string &recipientCity, const string &recipientState, const string &recipientZIP,
                     double weight, double costPerOunce, double additionalFeePerOunce)
            : Package(senderName, senderAddress, senderCity, senderState, senderZIP,
                      recipientName, recipientAddress, recipientCity, recipientState, recipientZIP,
                      weight, costPerOunce), additionalFeePerOunce(additionalFeePerOunce) {}

    // Calculate shipping cost including additional fee per ounce
    double calculateCost() const {
        return weight * (costPerOunce + additionalFeePerOunce);
    }
};

int main() {
    // Create objects of each type of Package and test calculateCost member function
    Package regularPackage("John Doe", "123 Main St", "Anytown", "CA", "12345",
                           "Jane Smith", "456 Elm St", "Sometown", "NY", "67890",
                           16.5, 0.5);

    TwoDayPackage twoDayPackage("John Doe", "123 Main St", "Anytown", "CA", "12345",
                                 "Jane Smith", "456 Elm St", "Sometown", "NY", "67890",
                                 16.5, 0.5, 5.0);

    OvernightPackage overnightPackage("John Doe", "123 Main St", "Anytown", "CA", "12345",
                                       "Jane Smith", "456 Elm St", "Sometown", "NY", "67890",
                                       16.5, 0.5, 2.0);

    cout << "Regular Package Cost: $" << regularPackage.calculateCost() << endl;
    cout << "Two-Day Package Cost: $" << twoDayPackage.calculateCost() << endl;
    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;

    return 0;
}
