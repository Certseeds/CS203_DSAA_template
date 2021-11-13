use std::sync::atomic::{AtomicI64, AtomicUsize};
use std::sync::atomic::Ordering;

use crate::lib::shape::shape;
use crate::lib::shape::shape::Shape;

pub struct CStereoShape {}

impl CStereoShape {
    pub fn value() -> i64 {
        return C_STEREO_SHAPE_NUM.load(Ordering::SeqCst);
    }
}

impl Shape for CStereoShape {}

pub static C_STEREO_SHAPE_NUM: AtomicI64 = AtomicI64::new(0i64);

impl Default for CStereoShape {
    fn default() -> CStereoShape {
        C_STEREO_SHAPE_NUM.fetch_add(1i64, Ordering::SeqCst);
        CStereoShape {}
    }
}

impl Drop for CStereoShape {
    fn drop(&mut self) {
        C_STEREO_SHAPE_NUM.fetch_sub(1i64, Ordering::SeqCst);
    }
}