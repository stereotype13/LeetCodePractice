/*
This was all in SQL

# Write your MySQL query statement below
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM
Person LEFT JOIN Address
ON Person.PersonId = Address.PersonId
*/