-- 코드를 입력하세요
SELECT mcdp_cd as '진료과 코드', count(*) as '5월예약건수'
from appointment
where apnt_ymd like "2022-05%"
group by MCDP_CD
order by count(*), MCDP_CD