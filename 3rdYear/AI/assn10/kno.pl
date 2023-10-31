malaria :- fever, 
           verify(chills).
dengue :- fever, 
          verify(rash),
          verify(muscle_pain).
measles :- fever,
           verify(cough),
           verify(runny_nose), verify(watery_eyes).
measles :- verify(rash).
influenza :- fever, 
            verify(cough),
            verify(not_runny_nose), verify(not_watery_eyes).
conjunctivitis :- verify(redness_in_eye), 
                  verify(sensitivity_to_light).
asthma :- verify(cough),
          verify(chest_pain),
          verify(shortness_of_breath).
thyroid :- verify(tiredness),
           verify(dry_skin),
           verify(weight_gain).
gallbladder_stone :- verify(pain_in_abdomen),
                     verify(nausea).
tuberculosis :- fever,
                verify(weight_loss),
                verify(loss_of_apetite).
ebola :- fever,
         verify(pain_in_abdomen),
         verify(loss_of_apetite),
         verify(sore_throat).
