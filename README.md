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

## 2. Structural Pattern: Adapter
```mermaid
classDiagram
    class ScoreAdapter {
        -matrix[3][3] int
        +evaluateMatch(p1: Move*, p2: Move*) int
    }
    class Move {
        <<interface>>
        +getId() int*
    }
    
    ScoreAdapter ..> Move : extracts IDs from
```
## 3. Behavioral Pattern: Strategy
```mermaid
classDiagram
    class ComputerStrategy {
        <<interface>>
        +getChoice() int*
    }
    class RandomStrategy {
        +getChoice() int
    }
    class RockHeavyStrategy {
        +getChoice() int
    }
    class Game {
        #aiStrategy: ComputerStrategy*
        +Game(strategy: ComputerStrategy*)
        +run() void
    }
    
    ComputerStrategy <|-- RandomStrategy : implements
    ComputerStrategy <|-- RockHeavyStrategy : implements
    Game o-- ComputerStrategy : has-a
```
