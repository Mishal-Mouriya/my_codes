#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. CLASS
// A blueprint that defines the data and behavior for objects.
// ==========================================
class ElectronicComponent
{
// Access specifiers: 'private' means these variables can only be accessed directly from within this class.
private:
    string name;
    double operatingVoltage;

public:   
    
    // A. Default Constructor (Takes no arguments)
    ElectronicComponent() 
    {
        name = "Unassigned Component";
        operatingVoltage = 0.0;
        cout << "[Base] Default Constructor called for: " << name << "\n";
    }

    // B. Parameterized Constructor (Takes arguments to set custom initial values)
    ElectronicComponent(string compName, double voltage) 
    {
        name = compName;
        operatingVoltage = voltage;
        cout << "[Base] Parameterized Constructor called for: " << name << "\n";
    }

    // ==========================================
    // 5. SETTERS (Mutators)
    // Public methods used to safely update private data.
    // ==========================================
    void setName(string compName) 
    {
        name = compName;
    }
    
    void setVoltage(double voltage)
    {
        if (voltage > 0) 
        { 
            // Setters are great for input validation!
            operatingVoltage = voltage;
        } 
        else 
        {
            cout << "Error: Voltage must be positive.\n";
        }
    }

    // ==========================================
    // 6. GETTERS (Accessors)
    // Public methods used to safely read private data.
    // ==========================================

    string getName() 
    {
        return name;
    }

    double getVoltage() 
    {
        return operatingVoltage;
    }

    // A standard class method to display object data
    void displaySpecs() 
    {
        cout << "Component: " << name << " | Operating Voltage: " << operatingVoltage << "V\n";
    }
};

// ==========================================
// The 'Microcontroller' class inherits from 'ElectronicComponent'.
// It gets all public methods (like getters/setters) from the Base class, 
// and adds its own specific features.
// ==========================================

class Microcontroller : public ElectronicComponent 
{
    private:
        int digitalPins;
        bool hasWiFi;

    public:
        // Constructor for the Derived class.
        // We use a "member initializer list" to explicitly call the parameterized 
        // constructor of the Base class so it handles 'compName' and 'voltage'.
        Microcontroller(string compName, double voltage, int pins, bool wifi) 
            : ElectronicComponent(compName, voltage) { 
            digitalPins = pins;
            hasWiFi = wifi;
            cout << "[Derived] Parameterized Constructor called for MCU: " << compName << "\n";
        }

        // Derived class Setter
        void setDigitalPins(int pins)
        {
            digitalPins = pins;
        }

        // Derived class Getter
        int getDigitalPins() 
        {
            return digitalPins;
        }

        // A method specific to the child class
        void displayMicroSpecs() 
        {
            cout << "--- MCU SPECS ---\n";
            displaySpecs(); // Reusing the Base class method!
            cout << "Digital Pins: " << digitalPins << " | WiFi Enabled: " << (hasWiFi ? "Yes" : "No") << "\n";
        }
};

// ==========================================
// MAIN FUNCTION (Execution starts here)
// ==========================================
int main() {
    cout << "\n=== DEMONSTRATING CONSTRUCTOR OVERLOADING ===" << endl;
    
    // 2. OBJECTS    
    ElectronicComponent blankComponent; 
    
    // Uses the Parameterized Constructor
    ElectronicComponent sensor("Ultrasonic Sensor", 5.0); 

    cout << "\n=== DEMONSTRATING GETTERS AND SETTERS ===" << endl;
    
    // We cannot do blankComponent.name = "LED"; because 'name' is private.
    // We MUST use the Setter.
    blankComponent.setName("LED");
    blankComponent.setVoltage(3.3);

    // Reading the updated values using Getters
    cout << "Updated Component Name: " << blankComponent.getName() << endl;
    cout << "Updated Component Voltage: " << blankComponent.getVoltage() << "V" << endl;

    cout << "\n=== DEMONSTRATING INHERITANCE ===" << endl;
    
    // Creating a child object. This triggers both the Base and Derived constructors.
    Microcontroller myBoard("NodeMCU ESP8266", 3.3, 17, true);

    cout << "\n=== FINAL COMPONENT OUTPUTS ===" << endl;
    blankComponent.displaySpecs();
    sensor.displaySpecs();
    cout << "\n";
    myBoard.displayMicroSpecs(); // Calling the inherited and extended method

    return 0;
}