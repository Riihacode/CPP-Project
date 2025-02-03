#include <iostream>
#include <string>
using namespace std;

const string 
    level_stress_low = "10-20: Low level stress",
    level_stress_moderate = "21-30: Moderate level stress",
    level_stress_high = "31-40: High level stress",
    level_stress_severe = "41-50: Severe level stress"
;

string 
    name,
    gender,
    address,
    job,
    form_date_input
;

int questionnaireResult[10];

void sectionQuestionnaireBiodata();
void sectionQuestionnaireQuestions();
void sectionQuestionnaireResult();

int main (){
    sectionQuestionnaireBiodata();
    sectionQuestionnaireQuestions();
    sectionQuestionnaireResult();

    return 0;
}

void sectionQuestionnaireBiodata(){
    string questionnaireQuestions= "";

}

void sectionQuestionnaireQuestions(){

}

void sectionQuestionnaireResult(){

}