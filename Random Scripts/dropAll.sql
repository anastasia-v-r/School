-- For use in OracleAPEX v12c
SELECT ('DROP TABLE ' || table_name || ' CASCADE CONSTRAINTS;') AS "Drop List" 
FROM user_tables;