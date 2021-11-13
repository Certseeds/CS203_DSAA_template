mod lib;

extern "C" {
    pub fn utf8_to_codepoint(
        u: *const ::std::os::raw::c_uchar,
        lenptr: *mut ::std::os::raw::c_int,
    ) -> ::std::os::raw::c_uint;
}

mod ass3_03 {
    use std::cmp::{max, Ordering};
    use std::io::{BufRead, Read};

    use crate::lib::unicode_block::find_alphabeta;
    use crate::lib::unicode_block::UnicodeBlock;
    use crate::utf8_to_codepoint;

    const UNICODE_PART_NUMBER: usize = 300usize;

    fn read_blocks() -> Vec<UnicodeBlock> {
        let mut block = std::fs::File::open("./Assignment_3/Blocks.txt").expect("File Not Exist");
        let mut will_return = String::new();
        block.read_to_string(&mut will_return).expect("Read Block.txx Fail");
        let mut blocks: Vec<UnicodeBlock> = Vec::new();
        for block in will_return.split('\n') {
            if block.starts_with('#') || block.trim().is_empty() {
                continue;
            }
            blocks.push(block.trim().parse::<UnicodeBlock>().expect("Parse Error"));
        }
        blocks
    }

    pub(crate) fn main() {
        let blocks = read_blocks();
        for i in blocks.iter() {
            println!("{}", i);
        }
        let mut visit_map = vec![0usize; blocks.len()];
        let mut input_str = read_all_from_stdio();
        let mut order = 0usize;
        let mut bytes_in_char = 0i32;
        while order < input_str.as_bytes().len() {
            let mut ch = &input_str.as_bytes()[order] as *const u8;
            let mut num_ptr = &mut bytes_in_char as *mut i32;
            let code_point: u32;
            unsafe {
                code_point = utf8_to_codepoint(ch, num_ptr);
            }
            let loca = find_alphabeta(&blocks, code_point).expect("noerr");
            visit_map[loca] += 1;
            order += bytes_in_char as usize;
        }
        let max_posi = visit_map.iter().enumerate().max_by(|a, b| {
            return a.1.cmp(b.1);
        });
        match max_posi {
            Some((order, value)) => { println!("{}", blocks[order]) }
            None => { println!("Error") }
        }
    }

    fn read_all_from_stdio() -> String {
        let mut will_return = String::new();
        let stdin = std::io::stdin();
        let mut lines = stdin.lock().lines();
        while let Some(line) = lines.next() {
            let line_str = line.expect("aaa");
            will_return.push_str(line_str.as_str());
        }
        will_return
    }
}

fn main() {
    ass3_03::main();
}