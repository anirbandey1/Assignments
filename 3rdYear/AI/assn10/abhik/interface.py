import sqlite3
from pyswip import Prolog

# Initialize the Prolog engine
prolog = Prolog()

# Load the Prolog knowledge base
prolog.consult('medical_rules.pl')

# Connect to the SQLite database
conn = sqlite3.connect('patient_data.db')
cursor = conn.cursor()

# Create a table for patient records if it doesn't exist
cursor.execute('''
CREATE TABLE IF NOT EXISTS patients (
    id INTEGER PRIMARY KEY,
    name TEXT,
    age INTEGER,
    symptoms TEXT,
    diagnosis TEXT
);
''')

# Define a function for diagnosis
def diagnose(symptoms):
    # Assert symptoms as facts in Prolog
    for symptom in symptoms:
        prolog.assertz(f'symptom({symptom}).')

    # Query Prolog for a diagnosis
    diagnosis = list(prolog.query('diagnose(Disease).'))

    # Remove asserted symptoms
    for symptom in symptoms:
        prolog.retract(f'symptom({symptom}).')

    return [result['Disease'] for result in diagnosis]

# User input
user_symptoms = ['fever', 'headache', 'fatigue']  # Replace with user input

# Perform diagnosis
diagnoses = diagnose(user_symptoms)

if diagnoses:
    diagnosis_text = ', '.join(diagnoses)
else:
    diagnosis_text = "No diagnosis found."

# Store patient data and diagnosis result in the database
name = 'John Doe'  # Replace with the patient's name
age = 30  # Replace with the patient's age

cursor.execute('INSERT INTO patients (name, age, symptoms, diagnosis) VALUES (?, ?, ?, ?)',
               (name, age, ', '.join(user_symptoms), diagnosis_text))
conn.commit()

print(f"Possible diagnoses: {diagnosis_text}")
