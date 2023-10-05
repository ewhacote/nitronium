//
// Created by KangMinji on 2023-10-05.
// https://school.programmers.co.kr/learn/courses/30/lessons/59041

-- 코드를 입력하세요
SELECT NAME, COUNT(NAME) AS COUNT
FROM ANIMAL_INS
WHERE NAME IS NOT NULL
		GROUP BY NAME
HAVING COUNT(*) >= 2
ORDER BY NAME