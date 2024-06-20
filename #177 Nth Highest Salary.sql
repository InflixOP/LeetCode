CREATE FUNCTION getnthhighestsalary(N INT) RETURNS INT
BEGIN
  SET N=N-1;
  RETURN (SELECT DISTINCT salary
      FROM employee
      ORDER BY salary DESC
      LIMIT 1 OFFSET N
  );
END
