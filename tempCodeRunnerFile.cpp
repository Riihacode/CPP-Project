#include <iostream>
#include <string>
using namespace std;

// Global variable
int arrayQuestionResult[10];

string 
    name, 
    address, 
    job, 
    age, 
    gender, 
    latest_history_disease, 
    input_date
;

string 
    level_stress_low        = "10-20: Low stress level",
    level_stress_moderate   = "21-30: Moderate stress level",
    level_stress_high       = "31-40: High stress level",
    level_stress_severe     = "41-50: Severe stress level"
;

// =====================================================================
//forward declaration
void sectionQuestion();
void sectionBiodata();
void sectionResult();

// =====================================================================
int main(){
    sectionBiodata();
    sectionQuestion();
    sectionResult();
}

// =====================================================================
void sectionBiodata(){
    cout << "Name           = ";
    getline(cin, name);
    cout << "Address        = ";
    getline(cin, address);
    cin.ignore();

    cout << "Age            = ";
    cin >> age;

    cout << "Gender         = ";
    cin >> gender;

    cin.ignore();
    cout << "Latest disease = ";
    getline(cin, latest_history_disease);

    cout << "Check up date  = ";
    getline(cin, input_date);

    cout << endl;
}

void sectionQuestion(){
    bool doQuestionnier = false;

    string rating = R"(Instruction: Please rate each statement based on how often it applies to you during your job. Use the following scale!
    1 = Never
    2 = Rarely
    3 = Sometimes
    4 = Often
    5 = Always
    )";

    string arrayQuestion[10] = {
        "I feel overwhelmed by the amount of work i have to do? ",
        "I experienced physical symptomps (headaches, fatigue, etc) due to work-related stress? ",
        "I feel like I don't have enough time to complete my task? ",
        "I worry about making mistakes in my job? ",
        "I find it difficult to balance my work and personal life? ",
        "I feel pressured by my supervisors/manager to meet high expectations? ",
        "I have difficulty concentrating on work because of stress? ",
        "I find myself working extra hours to meet deadlines? ",
        "I feel supported by my colleagues when I'm under pressure? ",
        "I feel burned out from my job? "
    };

    cout << rating << endl;

    for(int numberOfLoop = 0; numberOfLoop < 10; numberOfLoop++){
        int numberOfQuestion = numberOfLoop + 1;
        int answerOfQuestion;
        
        do{
            cout << "Number Of Question-" << numberOfQuestion << endl;
            cout << arrayQuestion[numberOfLoop] << endl;
            cout << "Answer = ";
            cin >> answerOfQuestion;
            cout << endl;

            if(answerOfQuestion < 1 || answerOfQuestion > 5){
                cout << "Your answer is invalid" << endl << endl;
            }
        } while(answerOfQuestion < 1 || answerOfQuestion > 5);
        
        arrayQuestionResult[numberOfLoop] = answerOfQuestion;
        cout << endl;
    }
}

void sectionResult(){
    int totalAnswerPoint = 0;

    cout << "======= Analysis Result ======="<< endl;
    cout << name << endl;
    cout << address << endl;
    cout << job << endl;
    cout << age << endl;
    cout << gender << endl;
    cout << latest_history_disease << endl;
    cout << input_date << endl;
    cout << "===============================" << endl; 

    cout << endl;

    for(int numberOfLoop = 0; numberOfLoop < 10; numberOfLoop++){
        totalAnswerPoint = totalAnswerPoint + arrayQuestionResult[numberOfLoop];
    }

    cout << "Your total answer point is " << totalAnswerPoint << endl;
    
    if (totalAnswerPoint >50){
        cout << "Unknown"<< endl;
    } else if(totalAnswerPoint >40){
        cout << "Your stress level is " << level_stress_severe;
    } else if (totalAnswerPoint >30){
        cout << "Your stress level is " << level_stress_high;
    } else if (totalAnswerPoint >20){
        cout << "Your stress level is " << level_stress_moderate;
    } else if (totalAnswerPoint >=10){
        cout << "Your stress level is " << level_stress_low;
    } else {
        cout << "Unknown" << endl;
    }
}