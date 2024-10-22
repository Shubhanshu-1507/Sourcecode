-- Create the database
CREATE DATABASE IF NOT EXISTS TMA_data;

-- Use the newly created database
USE TMA_data;

-- Create the table
CREATE TABLE IF NOT EXISTS recruitment_data (
    Location VARCHAR(50),
    Department VARCHAR(50),
    Headcount_Available INT,
    Offers_Made_Firm1 INT,
    Offers_Made_Firm2 INT,
    Offers_Made_Firm3 INT,
    Total_Offers_Made INT,
    Offers_Accepted_Firm1 INT,
    Offers_Accepted_Firm2 INT,
    Offers_Accepted_Firm3 INT,
    Total_Offers_Accepted INT
);

-- Insert data into the table
INSERT INTO recruitment_data
    (Location, Department, Headcount_Available, Offers_Made_Firm1, Offers_Made_Firm2, Offers_Made_Firm3, Total_Offers_Made,
    Offers_Accepted_Firm1, Offers_Accepted_Firm2, Offers_Accepted_Firm3, Total_Offers_Accepted)
VALUES
    ('Singapore', 'IT Systems', 335, 183, 92, 30, 254, 67, 42, 20, 109),
    ('Singapore', 'Corporate Services', 130, 206, 41, 41, 288, 24, 10, 32, 66),
    ('Singapore', 'Customer Service', 118, 295, 57, 29, 381, 53, 12, 21, 86),
    ('Singapore', 'Operations', 290, 187, 22, 14, 223, 55, 4, 10, 69),
    ('Singapore', 'Customer Support', 150, 86, 21, 19, 126, 14, 1, 10, 25),
    ('Singapore', 'Total', 1023, 957, 233, 133, 1323, 213, 69, 93, 375),

    ('Hong Kong', 'IT Systems', 125, 123, 58, 12, 193, 43, 5, 1, 49),
    ('Hong Kong', 'Corporate Services', 125, 151, 21, 10, 182, 24, 1, 2, 27),
    ('Hong Kong', 'Customer Service', 170, 197, 41, 21, 259, 74, 12, 4, 90),
    ('Hong Kong', 'Operations', 160, 57, 43, 24, 124, 33, 9, 10, 52),
    ('Hong Kong', 'Customer Support', 90, 48, 12, 12, 72, 11, 2, 6, 19),
    ('Hong Kong', 'Total', 670, 576, 175, 79, 830, 185, 29, 23, 237),

    ('Tokyo', 'Customer Service', 110, 148, 39, 30, 217, 27, 2, 10, 39),
    ('Tokyo', 'Customer Support', 90, 43, 15, 12, 70, 21, 2, 9, 32),
    ('Tokyo', 'Total', 200, 191, 54, 42, 287, 48, 4, 19, 71),

    ('Overall', 'Total', 1562, 1824, 462, 254, 2538, 446, 102, 135, 683);





