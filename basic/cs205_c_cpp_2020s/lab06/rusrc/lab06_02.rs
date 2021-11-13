mod lab06_02 {
    use std::fmt::Error;

    const VOWEL: [char; 5] = ['a', 'e', 'i', 'o', 'u'];

    pub fn isalpha(str: &str) -> Result<Option<bool>, Error> {
        let first_char = str.chars().nth(0).expect("Should Not Empty");
        if first_char == 'q' {
            return Err(Error);
        }
        if first_char.is_ascii_alphabetic() {
            return Ok(Some(VOWEL.contains(&first_char)));
        }
        return Ok(None);
    }

    pub(crate) fn main() {
        let teno = 'a';
        println!("Enter words (q to quit):");
        let mut input_str = String::new();
        let mut vowel = 0;
        let mut consonants = 0;
        let mut other = 0;
        'outer: while std::io::stdin().read_line(&mut input_str).expect("read fail") != 0 {
            let words = input_str.trim().split(" ");
            for word in words {
                match isalpha(word.trim()) {
                    Err(E) => break 'outer,
                    Ok(Some(true)) => vowel += 1,
                    Ok(Some(false)) => consonants += 1,
                    Ok(None) => other += 1,
                }
            }
            input_str.clear();
        }
        println!(r#"    {} words begining with vowels
    {} words begining with consonants
    {} others"#, vowel, consonants, other);
    }
}

pub fn main() { lab06_02::main(); }
