import json
import psycopg2

# Load JSON file
file_path = "F:\digital_literacy_dataset.json"  # Adjust this path if needed
with open(file_path, "r") as f:
    data = json.load(f)

# Connect to PostgreSQL
conn = psycopg2.connect(
    dbname="heart_attack_db",
    user="postgres",
    password="Gargi18112004",
    host="localhost",
    port="5432"
)
cur = conn.cursor()

# Insert data into the table
for row in data:
    cur.execute("""
        INSERT INTO digital_literacy (
            user_id, age, gender, education_level, employment_status, household_income, 
            location_type, basic_computer_knowledge_score, internet_usage_score, 
            mobile_literacy_score, post_training_basic_computer_knowledge_score, 
            post_training_internet_usage_score, post_training_mobile_literacy_score, 
            modules_completed, average_time_per_module, quiz_performance, session_count, 
            engagement_level, adaptability_score, feedback_rating, skill_application, 
            employment_impact, overall_literacy_score
        ) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)
    """, (
        row["User_ID"], row["Age"], row["Gender"], row["Education_Level"], row["Employment_Status"],
        row["Household_Income"], row["Location_Type"], row["Basic_Computer_Knowledge_Score"], 
        row["Internet_Usage_Score"], row["Mobile_Literacy_Score"], row["Post_Training_Basic_Computer_Knowledge_Score"], 
        row["Post_Training_Internet_Usage_Score"], row["Post_Training_Mobile_Literacy_Score"], 
        row["Modules_Completed"], row["Average_Time_Per_Module"], row["Quiz_Performance"], 
        row["Session_Count"], row["Engagement_Level"], row["Adaptability_Score"], row["Feedback_Rating"], 
        row["Skill_Application"], row["Employment_Impact"], row["Overall_Literacy_Score"]
    ))

# Commit and close connection
conn.commit()
cur.close()
conn.close()

print("Data imported successfully!")
