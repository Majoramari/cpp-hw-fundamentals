#include <iostream>

using namespace std;

class Calculator {
private:
    enum class MathOperation { CLEAR, ADD, SUB, MUL, DIV };

    double current_result_ = 0;
    double previous_value_ = 0;
    MathOperation previous_operation_ = MathOperation::CLEAR;

    string get_operation_description() {
        switch (previous_operation_) {
            case MathOperation::CLEAR:
                return "Clearing";
            case MathOperation::ADD:
                return "Adding";
            case MathOperation::SUB:
                return "Subtracting";
            case MathOperation::MUL:
                return "Multiplying";
            case MathOperation::DIV:
                return "DIV";
        }
    }

public:
    void display_result() {
        cout << "Result After " << get_operation_description() << " " << previous_value_ << " is " << current_result_
             << endl;
    }

    void reset() {
        current_result_ = 0;
        previous_value_ = 0;
        previous_operation_ = MathOperation::CLEAR;
    }

    void add(double value) {
        current_result_ += value;
        previous_value_ = value;
        previous_operation_ = MathOperation::ADD;
    }

    void subtract(double value) {
        current_result_ -= value;
        previous_value_ = value;
        previous_operation_ = MathOperation::SUB;
    }

    void multiply(double value) {
        current_result_ *= value;
        previous_value_ = value;
        previous_operation_ = MathOperation::MUL;
    }

    void divide(double value) {
        current_result_ /= value;
        previous_value_ = value;
        previous_operation_ = MathOperation::DIV;
    }
};

int main() {
    Calculator calc;

    calc.add(5); // NOLINT
    calc.display_result();

    calc.subtract(10); // NOLINT
    calc.display_result();

    calc.multiply(2); // NOLINT
    calc.display_result();

    calc.divide(3);
    calc.display_result();

    calc.reset();
    calc.display_result();

    calc.add(50); // NOLINT
    calc.display_result();

    return 0;
}
