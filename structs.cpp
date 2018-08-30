
struct Notas {
  int nota;
  Notas* sgte;
};
struct InfoEst {
  int id;
  Notas* notas[4];
};

struct Estudiante {
  InfoEst infoest;
  Estudiante* sgte;
};


struct InfoCurso{
  int id;
  int promocionados;
  int regularizados;
  int recursantes;
  Estudiante* estudiantes;
};

struct Curso{
  InfoCurso infoCurso;
  Curso* sgte;
};

struct Archivo {
  int idCurso;
  int idEst;
  int parcial;
  int nota;

};