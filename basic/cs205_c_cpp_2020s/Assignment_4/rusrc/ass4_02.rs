use lib::ass4_01::ass4 as ass4_01;
use lib::ass4_02::ass4 as ass4_02;

mod lib;

fn main() {
    let m = ass4_01::question1();
    ass4_02::question2(&m);
}