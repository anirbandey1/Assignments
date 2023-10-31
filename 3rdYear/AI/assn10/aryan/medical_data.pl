% Name - Anirban Dey
% Roll - 002111001108


% Define symptoms for various diseases
symptom(fever).
symptom(cough).
symptom(headache).
symptom(rash).
symptom(fatigue).
symptom(joint_pain).
symptom(shortness_of_breath).
symptom(chest_pain).
symptom(sore_throat).
symptom(abdominal_pain).
symptom(vomiting).
symptom(diarrhea).
symptom(nausea).
symptom(blurred_vision).
symptom(frequent_urination).
symptom(weight_loss).
symptom(swelling).
symptom(persistent_cough).
symptom(bruising).
symptom(blood_in_urine).

% Define diseases and their associated symptoms
disease(common_cold, [fever, cough, headache]).
disease(influenza, [fever, cough, fatigue, sore_throat]).
disease(measles, [fever, cough, rash]).
disease(asthma, [shortness_of_breath, chest_pain, cough]).
disease(bronchitis, [cough, fatigue, chest_pain]).
disease(strep_throat, [fever, sore_throat]).
disease(pneumonia, [fever, cough, shortness_of_breath]).
disease(appendicitis, [abdominal_pain, vomiting, nausea]).
disease(kidney_stones, [abdominal_pain, blood_in_urine, nausea]).
disease(food_poisoning, [vomiting, diarrhea, abdominal_pain]).
disease(diabetes, [frequent_urination, fatigue, blurred_vision]).
disease(hypertension, [headache, blurred_vision, fatigue, chest_pain]).
disease(lymphoma, [weight_loss, swelling, persistent_cough, fever]).
disease(leukemia, [fatigue, bruising, weight_loss, fever]).

% Rules for diagnosis
diagnose(Symptoms, Disease, MatchedSymptoms) :-
    disease(Disease, RequiredSymptoms),
    intersection(RequiredSymptoms, Symptoms, CommonSymptoms),
    length(CommonSymptoms, MatchedSymptoms).

% Find the disease with the most matched symptoms
find_most_likely_disease(Symptoms, MostLikelyDisease) :-
    findall(MatchedSymptoms-Disease, diagnose(Symptoms, Disease, MatchedSymptoms), DiseaseMatches),
    max_member(Max-MostLikelyDisease, DiseaseMatches),
    Max >= 2.

% Main diagnosis function
diagnose_disease :-
    write('Enter your symptoms (space-separated, e.g., fever cough fatigue): '),
    read_line_to_string(user_input, SymptomsInput),
    atomic_list_concat(SymptomsList, ' ', SymptomsInput),
    list_to_set(SymptomsList, Symptoms),
    (find_most_likely_disease(Symptoms, MostLikelyDisease) ->
        format('Based on your symptoms, you may have: ~w~n', [MostLikelyDisease]);
        write('Based on your symptoms, no specific disease could be determined.'), nl
    ).

% Interaction with the user
start_diagnosis :-
    write('Welcome to the Medical Diagnosis Expert System.'), nl,
    write('Let\'s diagnose your disease based on your symptoms.'), nl,
    diagnose_disease.
