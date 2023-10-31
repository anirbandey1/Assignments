
% Define facts about symptoms and diseases
symptom(fever).
symptom(headache).
symptom(fatigue).

% Define rules for diagnosing diseases
diagnose(malaria) :- 
    symptom(fever),
    symptom(headache),
    symptom(fatigue).


