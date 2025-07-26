#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class User {
    string name;
    int age;
    float weight;
    float height;
    string goal;

public:
    void inputData() {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your weight (kg): ";
        cin >> weight;
        cout << "Enter your height (in meters): ";
        cin >> height;
        cin.ignore(); 
        cout << "Enter your goal (lose/gain/maintain): ";
        getline(cin, goal);
    }

    void showPlan() {
        cout << "\nHello " << name << "!" << endl;
        cout << "Based on your goal: " << goal << ", here is your plan:\n";

        if (goal == "lose") {
            cout << "\nDiet Plan:\n";
            cout << "  - Breakfast: Oats and fruit\n";
            cout << "  - Lunch: Brown rice and vegetables\n";
            cout << "  - Dinner: Soup and salad\n";
            cout << "  - Night walk: After eating, walk 10-15 minutes\n";

            cout << "\nWorkout Plan:\n";
            cout << "  - 30 min walk\n";
            cout << "  - 15 min stretching\n";
        }
        else if (goal == "gain") {
            cout << "\nDiet Plan:\n";
            cout << "  - Breakfast: Eggs and toast\n";
            cout << "  - Lunch: Chicken and rice\n";
            cout << "  - Dinner: Paneer and roti\n";

            cout << "\nWorkout Plan:\n";
            cout << "  - Strength training\n";
            cout << "  - 10 min cardio\n";
        }
        else if (goal == "maintain") {
            cout << "\nDiet Plan:\n";
            cout << "  - Balanced meals (Protein + Veggies + Carbs)\n";
            cout << "  - Drink 2-3 liters of water\n";

            cout << "\nWorkout Plan:\n";
            cout << "  - 20 min yoga or jogging\n";
        }
        else {
            cout << "\nInvalid goal entered. Please use: lose, gain, or maintain.\n";
        }
    }

    void waterReminder() {
        float recommended = weight * 0.033;
        float drank;
        cout << "\n?? Water Intake Reminder ??\n";
        cout << "Based on your weight, you should drink about " << recommended << " liters of water today.\n";
        cout << "How much water did you drink today (liters)? ";
        cin >> drank;

        if (drank >= recommended) {
            cout << "? Great job! You're well hydrated!\n";
        } else {
            cout << "? You need to drink " << (recommended - drank) << " more liters today.\n";
            cout << "Don't forget to drink water regularly! ??\n";
        }
    }

    void calorieGoal() {
        cout << "\n?? Estimated Daily Calorie Goal:\n";
        if (goal == "lose")
            cout << "  ? About 1600-1800 kcal/day recommended.\n";
        else if (goal == "gain")
            cout << "  ? About 2500-2800 kcal/day recommended.\n";
        else if (goal == "maintain")
            cout << "  ? About 2000-2200 kcal/day recommended.\n";
        else
            cout << "  ? Unknown goal. Calorie target not available.\n";
    }

    void motivationTip() {
        cout << "\n?? Daily Motivation Tip:\n";
        cout << "  \"Small steps every day lead to big results. Keep going!\"\n";
    }

    void saveToFile() {
        ofstream file((name + "_profile.txt").c_str());
        if (file.is_open()) {
            file << "Name: " << name << "\n";
            file << "Age: " << age << "\n";
            file << "Weight: " << weight << " kg\n";
            file << "Height: " << height << " m\n";
            file << "Goal: " << goal << "\n";
            file.close();  
        } else {
            cout << "? Error saving file.\n";
        }
    }
};

int main() {
    User u;
    u.inputData();
    u.showPlan();
    u.calorieGoal();
    u.waterReminder();
    u.motivationTip();
    u.saveToFile();
return 0;
}
