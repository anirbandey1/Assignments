'''

Name : Anirban Dey
Roll : 002111001108

Question:-

Patients seek medical help for determination (or diagnosis) and treatment of various health problems. Sometimes a combination of the patient’s history and a clinical examination by a physician are enough to make diagnoses and decide whether medical treatment is needed, and what treatment should be given. However, often laboratory investigations or diagnostic imaging procedures are required to confirm a clinically suspected diagnosis or to obtain more accurate information.

For example, malaria may be suspected by the presence of fever and by excluding other causes of fever on history and physical examination, but a firm diagnosis is made on microscopic examination of a blood slide.

Implement an Expert System for medical disease diagnosis facilities with several human diseases using methodology of rule-based systems; Knowledge-based systems; Intelligent agent (IA); Database methodology; Inference engine; and System-user interaction.

You can use Python and Prolog language as per your requirements.


Install latest version of pyswip from git
pip install git+https://github.com/yuce/pyswip@master#egg=pyswip

'''

from pyswip import Prolog

# Initialize Prolog
prolog = Prolog()

# Load your Prolog code file (assuming the Prolog code is saved in a file named 'diagnosis.pl')
prolog.consult('medical_data.pl')

number_of_times_diagnosis = 2

for i in range(number_of_times_diagnosis):

    # Run the diagnosis
    for result in prolog.query("start_diagnosis."):
        pass

