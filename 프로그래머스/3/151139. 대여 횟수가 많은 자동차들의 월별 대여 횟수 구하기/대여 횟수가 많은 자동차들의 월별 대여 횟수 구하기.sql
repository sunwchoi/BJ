-- 코드를 입력하세요
SELECT MONTH(start_date) as MONTH, CAR_ID, count(history_id) as RECORDS
from car_rental_company_rental_history
where start_date between '20220801' and '20221031'
    and car_id in (
        select car_id
        from car_rental_company_rental_history
        where start_date between '20220801' and '20221031'
        group by car_id
        having count(history_id) >= 5 
    )
group by date_format(start_date, '%Y-%m'), car_id
order by date_format(start_date, '%Y-%m'), car_id desc