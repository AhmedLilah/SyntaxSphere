use crate::lib::project::Project;

#[derive(Debug)]
pub struct Person {
    pub name: String,
    pub project: Option<Project>,
}
