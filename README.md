# C++ Rock Paper Scissors game

## UML Sınıf Diyagramları (Önce / Sonra)
### 1. Sonra (Faz 1 - Factory Method Sonrası)

```mermaid
classDiagram
    class Move {
        <<interface>>
        +getName() string*
        +getId() int*
    }
    class Rock {
        +getName() string
        +getId() int
    }
    class Paper {
        +getName() string
        +getId() int
    }
    class Scissors {
        +getName() string
        +getId() int
    }
    class MoveFactory {
        +createMove(choice: int) Move*
    }
    
    Move <|-- Rock : implements
    Move <|-- Paper : implements
    Move <|-- Scissors : implements
    MoveFactory ..> Move : creates
```
