#include<iostream>
#include<string>
using namespace std;

class Question{
    public:
    string questext;
    string options[4];
    char correct_option;

    void ask() {
        cout<< questext <<endl;
        for (int i=0;i<4;i++){
            cout<< options[i]<<endl;
        }
        cout << "Your answer (A/B/C/D): ";
    }

    bool check_answer(char user_answer){
        return toupper(user_answer)==toupper(correct_option);
    }
};
void load_questions(Question questions[], int &numQuestions) {
    numQuestions = 7; 

    questions[0].questext = "What is the capital of Nepal?";
    questions[0].options[0] = "A. Kathmandu";
    questions[0].options[1] = "B. Pokhara";
    questions[0].options[2] = "C. Lalitpur";
    questions[0].options[3] = "D. Bhaktapur";
    questions[0].correct_option = 'A';

    questions[1].questext = "Which planet is known as the Green Planet?";
    questions[1].options[0] = "A. Earth";
    questions[1].options[1] = "B. Mars";
    questions[1].options[2] = "C. Jupiter";
    questions[1].options[3] = "D. Venus";
    questions[1].correct_option = 'A';

    questions[2].questext = "Which is the largest country in the world?";
    questions[2].options[0] = "A. China";
    questions[2].options[1] = "B. USA";
    questions[2].options[2] = "C. Russia";
    questions[2].options[3] = "D. Japan";
    questions[2].correct_option = 'C';

    questions[3].questext = "Which is the smallest country in the world?";
    questions[3].options[0] = "A. China";
    questions[3].options[1] = "B. USA";
    questions[3].options[2] = "C. Vatican City";
    questions[3].options[3] = "D. Japan";
    questions[3].correct_option = 'C';

    questions[4].questext = "Which is the national flower of Nepal?";
    questions[4].options[0] = "A. Marigold";
    questions[4].options[1] = "B. Rose";
    questions[4].options[2] = "C. Rhododendron";
    questions[4].options[3] = "D. Lotus";
    questions[4].correct_option = 'C';

    questions[5].questext = "How many constituent colleges are there under IOE?";
    questions[5].options[0] = "A. 5";
    questions[5].options[1] = "B. 4";
    questions[5].options[2] = "C. 6";
    questions[5].options[3] = "D. 3";
    questions[5].correct_option = 'A';

    questions[6].questext = "How many districts are there in Nepal?";
    questions[6].options[0] = "A. 79";
    questions[6].options[1] = "B. 80";
    questions[6].options[2] = "C. 75";
    questions[6].options[3] = "D. 77";
    questions[6].correct_option = 'D';
}
void start_quiz() {
    Question questions[10];
    int numQuestions = 0;
    load_questions(questions, numQuestions);

    int score = 0;

    for (int i = 0; i < numQuestions; i++) {
        cout << "\nQuestion " << (i + 1) << ":" << endl;
        questions[i].ask();

        char answer;
        cin >> answer;

        if (questions[i].check_answer(answer)) {
            cout << "Yayyy Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! Correct answer was: " << questions[i].correct_option << endl;
        }
    }

    cout << "\n🎉 You scored " << score << " out of " << numQuestions << "." << endl;
}
int main() {
    int choice;

    do {
        cout << "\n===== QUIZ GAME =====" << endl;
        cout << "1. Start Quiz" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                start_quiz();
                break;
            case 2:
                cout << "👋 Thank you for playing!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 2);

    return 0;
}

