use std::fmt;
use std::str::FromStr;

pub struct UnicodeBlock {
    begin: usize,
    end: usize,
    part: String,
}


impl FromStr for UnicodeBlock {
    type Err = std::io::Error;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let strvec: Vec<&str> = s.trim()
            .split(&['.', ';'][..])
            .collect();
        let begin = usize::from_str_radix(strvec[0].trim(), 16).expect("begin error");
        let end = usize::from_str_radix(strvec[2].trim(), 16).expect("end error");
        let part = strvec[3].trim().parse::<String>().expect("part Error");
        Ok(UnicodeBlock {
            begin,
            end,
            part,
        })
    }
}

impl fmt::Display for UnicodeBlock {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(f, r#"{} {} {}"#, self.begin, self.end, self.part);
    }
}

pub fn find_alphabeta(blocks: &Vec<UnicodeBlock>, ch: u32) -> Result<usize, i32> {
    for (order, block) in blocks.iter().enumerate() {
        if block.begin <= ch as usize && ch as usize <= block.end {
            return Ok(order);
        }
    }
    return Err(-1); // Should not reach there
}
