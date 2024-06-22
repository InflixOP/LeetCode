select 
    request_at as "Day",
    round(
        (sum(case when status = "cancelled_by_driver" or status = "cancelled_by_client" then 1 else 0 end) / count(status)), 2
    ) as "Cancellation Rate"
from
    Trips
where 
    client_id not in (select users_id from Users where role = 'client' and banned ='Yes') 
and 
    driver_id not in (select users_id from Users where role = 'driver' and banned ='Yes') 
and 
    request_at >= "2013-10-01" and request_at <= "2013-10-03"
group by 
    request_at