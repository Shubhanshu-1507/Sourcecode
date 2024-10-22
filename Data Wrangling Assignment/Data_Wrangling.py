# Import necessary libraries
import mysql.connector
import pandas as pd
import matplotlib.pyplot as plt

# Function to establish connection to MySQL database
def connect_to_db():
    try:
        connection = mysql.connector.connect(
            host='localhost',  # Replace with your host
            user='root',  # Replace with your MySQL username
            password='Toor',  # Replace with your MySQL password
            database='TMA_data'  # Replace with your database name
        )
        if connection.is_connected():
            print("Connected to MySQL Server")
        return connection
    except mysql.connector.Error as e:
        print(f"Error: {e}")
        return None

# Function to create the easy_data table based on TMA_data table
def create_easy_data_table():
    connection = connect_to_db()
    if connection:
        cursor = connection.cursor()
        # Drop the easy_data table if it already exists, then recreate it
        cursor.execute("DROP TABLE IF EXISTS easy_data;")
        # Creating easy_data table with necessary columns and derived data
        cursor.execute(
            '''
            CREATE TABLE easy_data AS
            SELECT
                Location AS Location,
                Department,
                headcount AS Total_Headcount,
                Offers_Recruitment_Firm1 AS Offers_Made_Company1,
                Offers_Recruitment_Firm2 AS Offers_Made_Company2,
                Offers_Recruitment_Firm3 AS Offers_Made_Company3,
                Offers_Total AS Total_Offers,
                Acceptance_Recruitment_Firm1 AS Offers_Accepted_Company1,
                Acceptance_Recruitment_Firm2 AS Offers_Accepted_Company2,
                Acceptance_Recruitment_Firm3 AS Offers_Accepted_Company3,
                Acceptance_Total AS Total_Accepted_Offers
            FROM TMA_data;
            '''
        )
        connection.commit()
        print("Table easy_data created successfully.")
        connection.close()

# Create the easy_data table
create_easy_data_table()

# Function to create the fig1 table based on TMA_data table
def create_fig1_table():
    connection = connect_to_db()
    if connection:
        cursor = connection.cursor()
        # Drop the fig1 table if it exists and recreate it
        cursor.execute("DROP TABLE IF EXISTS fig1;")
        cursor.execute(
            '''
            CREATE TABLE fig1 AS
            SELECT
                Location AS Location,
                Department,
                SUM(headcount) AS Total_Headcount,
                SUM(CAST(SUBSTRING_INDEX(Offers_Recruitment_Firm1, '|', 1) AS UNSIGNED)) AS Offers_Made_Firm1,
                SUM(CAST(SUBSTRING_INDEX(Offers_Recruitment_Firm2, '|', 1) AS UNSIGNED)) AS Offers_Made_Firm2,
                SUM(CAST(SUBSTRING_INDEX(Offers_Recruitment_Firm3, '|', 1) AS UNSIGNED)) AS Offers_Made_Firm3,
                SUM(CAST(SUBSTRING_INDEX(Offers_Total, '|', 1) AS UNSIGNED)) AS Total_Offers_Made,
                SUM(CAST(SUBSTRING_INDEX(Acceptance_Recruitment_Firm1, '|', 1) AS UNSIGNED)) AS Offers_Accepted_Firm1,
                SUM(CAST(SUBSTRING_INDEX(Acceptance_Recruitment_Firm2, '|', 1) AS UNSIGNED)) AS Offers_Accepted_Firm2,
                SUM(CAST(SUBSTRING_INDEX(Acceptance_Recruitment_Firm3, '|', 1) AS UNSIGNED)) AS Offers_Accepted_Firm3,
                SUM(CAST(SUBSTRING_INDEX(Acceptance_Total, '|', 1) AS UNSIGNED)) AS Total_Offers_Accepted
            FROM TMA_data
            GROUP BY Location, Department;
            '''
        )
        connection.commit()
        print("Table fig1 created successfully.")
        connection.close()

# Create the fig1 table
create_fig1_table()

# Function to fetch data from easy_data table and return as a DataFrame
def fetch_data():
    connection = connect_to_db()
    if connection:
        try:
            query = "SELECT * FROM easy_data;"
            df = pd.read_sql(query, connection)  # Fetch data into a Pandas DataFrame
            return df
        except mysql.connector.Error as e:
            print(f"Error fetching data: {e}")
        finally:
            if connection.is_connected():
                connection.close()
                print("MySQL connection is closed")

# Fetch data from the easy_data table
df = fetch_data()
df.head()  # Display the first few rows of the DataFrame

# Function to display the table similar to your uploaded image using Matplotlib
def display_custom_table(df):
    fig, ax = plt.subplots(figsize=(16, 8))  # Adjust the size according to the table

    # Multi-level headers
    headers = [
        ['Location', 'Department', 'Headcount Available', 'Number of Offers Made', '', '', '', 'Number of Offers Accepted', '', '', ''],
        ['', '', '', 'Recruitment Firm 1', 'Recruitment Firm 2', 'Recruitment Firm 3', 'Total', 'Recruitment Firm 1', 'Recruitment Firm 2', 'Recruitment Firm 3', 'Total']
    ]

    df.columns = pd.MultiIndex.from_tuples(zip(*headers))

    # Hide axes
    ax.xaxis.set_visible(False)
    ax.yaxis.set_visible(False)
    ax.set_frame_on(False)

    # Create the table
    table = ax.table(cellText=df.values, colLabels=df.columns, cellLoc='center', loc='center')

    # Adjust font size and scale to fit content
    table.auto_set_font_size(False)
    table.set_fontsize(10)
    table.scale(1.2, 1.2)

    for (i, j), cell in table.get_celld().items():
        if i == 0 or i == 1:  # Header rows
            cell.set_text_props(weight='bold', color='white')
            cell.set_facecolor('#4B8BBE')
        elif i % 2 == 0:  # Alternating row colors
            cell.set_facecolor('#E8EAF6')
        else:
            cell.set_facecolor('white')

    plt.title('Recruitment Data Table', fontsize=16, pad=20)
    plt.show()

# Display the fetched data in a graphical table format
if df is not None:
    display_custom_table(df)
