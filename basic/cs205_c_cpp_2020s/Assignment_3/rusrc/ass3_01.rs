mod lib;

mod ass3_01 {
    use std::io::ErrorKind;
    use std::str::FromStr;

    use crate::lib::lib::read_a_int;

    const DIRECTION: [(i64, i64); 8] = [(1, 1),
        (1, 0),
        (1, -1),
        (0, 1),
        (0, -1),
        (-1, 1),
        (-1, 0),
        (-1, -1)];

    struct Bullet {
        x: i64,
        y: i64,
        dir_x: i64,
        dir_y: i64,
    }

    impl FromStr for Bullet {
        type Err = std::io::Error;
        fn from_str(s: &str) -> Result<Self, Self::Err> {
            let coords: Vec<&str> = s.trim()
                .split_whitespace()
                .collect();
            let x = coords[0].parse::<i64>().expect("1st error");
            let y = coords[1].parse::<i64>().expect("2nd error");
            let dir_x = coords[2].parse::<i64>().expect("3rd error");
            let dir_y = coords[3].parse::<i64>().expect("4th error");
            if !DIRECTION.contains(&(dir_x, dir_y)) {
                return Err(std::io::Error::from(ErrorKind::InvalidInput));
            }
            Ok(Bullet {
                x,
                y,
                dir_x,
                dir_y,
            })
        }
    }


    pub(crate) fn main() {
        let n: i64 = read_a_int("n");
        let m: i64 = read_a_int("m");
        let k: i64 = read_a_int("k");
        let mut bullets: Vec<Bullet> = Vec::new();
        for num in 0..k {
            println!("{} th line of buckets", num);
            bullets.push(read_a_bullet())
        }
        let mut vec = vec![vec![false; m as usize]; n as usize];
        for bullet in bullets {
            let mut x = bullet.x;
            let mut y = bullet.y;
            loop {
                if x < 0 || x >= n || y < 0 || y >= m {
                    break;
                }
                vec[x as usize][y as usize] = true;
                x += bullet.dir_x;
                y += bullet.dir_y;
            }
        }
        let mut result = 0i64;
        for line in vec.iter() {
            for point in line.iter() {
                result += match point {
                    true => { 0i64 }
                    false => { 1i64 }
                };
            }
        }
        println!("{}", result);
    }

    fn read_a_bullet() -> Bullet {
        let mut input_str = String::new();
        std::io::stdin().read_line(&mut input_str).expect("Input Wrong");
        match input_str.trim().parse::<Bullet>()
        {
            Ok(num) => { num }
            Err(_error) => {
                println!("Please Input Once Again;");
                read_a_bullet()
            }
        }
    }
}

fn main() {
    ass3_01::main();
}