DROP TABLE waycost;

CREATE TABLE waycost (
  point1 varchar not null,
  point2 varchar not null,
  cost integer default 0 not null
);

INSERT INTO waycost
  VALUES
    ('a', 'b', 10),
    ('a', 'c', 15),
    ('a', 'd', 20),
    ('b', 'a', 10),
    ('b', 'c', 35),
    ('b', 'd', 25),
    ('c', 'a', 15),
    ('c', 'b', 35),
    ('c', 'd', 30),
    ('d', 'a', 20),
    ('d', 'b', 25),
    ('d', 'c', 30);

WITH wco AS(
  WITH RECURSIVE wc AS (
    SELECT
      waycost.cost AS total_cost,
      waycost.point1 AS start,
      waycost.point1,
      waycost.point2,
      ARRAY[waycost.point1, waycost.point2] AS tour,
      ARRAY(SELECT point1 FROM waycost GROUP BY point1 ORDER BY 1) AS check
    FROM waycost
    union all
    SELECT
      wc.total_cost + waycost.cost,
      wc.start,
      waycost.point1,
      waycost.point2,
      array_append(tour, waycost.point2),
      wc.check
    FROM wc
      JOIN waycost
        ON waycost.point1 = wc.point2
      WHERE
        case
          when tour <@ wc.check  then not (tour && ARRAY[waycost.point2])
          else waycost.point2 = tour[1]
        end
  )
SELECT
    wc.total_cost + waycost.cost AS total_cost,
    array_append(tour, waycost.point2) AS tour
  FROM wc
  JOIN waycost
    ON waycost.point1 = wc.point2
  WHERE waycost.point2 = tour[1] and
        waycost.point1 = tour[array_length(wc.check, 1)] and
        tour[1] = 'a'
)

SELECT * FROM wco
WHERE wco.total_cost = (SELECT min(wco.total_cost) FROM wco)
order by wco.tour;
