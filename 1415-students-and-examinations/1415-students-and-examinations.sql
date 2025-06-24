# Write your MySQL query statement below

select t1.*,count(e.subject_name)as attended_exams
from (select * 
     from Students
     cross join Subjects)as t1
left join Examinations e
on t1.student_id = e.student_id and t1.subject_name = e.subject_name
group by t1.student_id,t1.subject_name 
ORDER BY 
    t1.student_id, t1.subject_name;

-- SELECT 
--     t1.*, 
--     COUNT(e.subject_name) AS attended_exams
-- FROM 
--     (SELECT * 
--      FROM Students
--      CROSS JOIN Subjects) AS t1
-- LEFT JOIN 
--     Examinations e
--     ON t1.student_id = e.student_id AND t1.subject_name = e.subject_name
-- GROUP BY 
--     t1.student_id, t1.student_name, t1.subject_name;
-- ORDER BY 
--     t1.student_id, t1.subject_name;


