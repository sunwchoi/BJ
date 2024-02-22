-- 코드를 입력하세요
select CAR_ID, car.CAR_TYPE, floor(daily_fee * 30 * ((100 - discount_rate)/ 100)) as FEE
from car_rental_company_car car
    join car_rental_company_discount_plan dc
    on car.car_type = dc.car_type
where car_id not in(
    SELECT car_id
    from car_rental_company_rental_history
    where end_date >= '2022-11-1' and start_date <= '2022-11-30'
    )
    and duration_type like '30일 이상'
    and car.car_type in ('세단', 'SUV')
having 500000 <= fee and fee < 2000000
order by fee desc, car_type, car_id desc