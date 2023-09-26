//
// Created by KangMinji on 2023-09-26.
// https://school.programmers.co.kr/learn/courses/30/lessons/59412

-- 코드를 입력하세요
SELECT HOUR(DATETIME) AS TIME, COUNT(DATETIME) AS COUNT
FROM ANIMAL_OUTS
GROUP BY TIME
		HAVING TIME >= 9 AND TIME < 20
ORDER BY TIME