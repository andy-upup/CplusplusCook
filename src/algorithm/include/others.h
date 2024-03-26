#ifndef OTHERS_H__
#define OTHERS_H__
#include <iostream>
#include <queue>
#include <vector>

namespace algo {

int JuiceNum(const int n);

class Instruction {
 public:
    enum class Stage { FETCH, EXECUTE, WRITE };
    Instruction(int data) : stage_(Stage::FETCH), data_(data), stage_idx_(0) {}
    void Execute() {
        stage_idx_ += 1;
        switch(stage_) {
            case Stage::FETCH: {
                std::cout << "Fetch instruction: " << data_ << std::endl;
                stage_ = Stage::EXECUTE;
                break;
            }
            case Stage::EXECUTE: {
                std::cout << "Execute: " << data_ << std::endl;
                stage_ = Stage::WRITE;
                break;
            }
            case Stage::WRITE: {
                std::cout << "Write back: " << data_ << std::endl;
                stage_ = Stage::FETCH;
                break;
            }
        }
    }
    int GetStageIdx() const {
        return stage_idx_;
    }
 private:
    Stage stage_;
    int data_;
    int stage_idx_;
};

class PipelineStage {
 public:
    void Push(Instruction* inst) {
        insts_.push(inst);
    }

    void Tick() {
        if (!insts_.empty()) {
            auto inst = insts_.front();
            inst->Execute();
            if (inst->GetStageIdx() == 3) {
                insts_.pop();
            }
        }
    }
 private:
    std::queue<Instruction*> insts_;
};

class ThreeStagePipeline {
 public:
    void Run(std::vector<Instruction>& insts) {
        if (insts.empty()) {
            return;
        }
        const int num = insts.size();
        const int group_num = num / 3;
        const int rest_num = num % 3;
        for (int i = 0; i < group_num; ++i) {
            a_stage_.Push(&insts[i * 3]);
            b_stage_.Push(&insts[i * 3 + 1]);
            c_stage_.Push(&insts[i * 3 + 2]);
        }
        if (rest_num == 1) {
            a_stage_.Push(&insts[group_num * 3]);
        } else if (rest_num == 2) {
            a_stage_.Push(&insts[group_num * 3]);
            b_stage_.Push(&insts[group_num * 3 + 1]);
        }

        a_stage_.Tick();
        a_stage_.Tick();
        b_stage_.Tick();
        const int tick_num = insts.size() - 2 + 4;
        for (int i = 2; i < tick_num - 2; ++i) {
            a_stage_.Tick();
            b_stage_.Tick();
            c_stage_.Tick();
        }
        if (rest_num == 0) {
            b_stage_.Tick();
            c_stage_.Tick();
            c_stage_.Tick();
        } else if (rest_num == 1) {
            a_stage_.Tick();
            c_stage_.Tick();
            a_stage_.Tick();
        } else if (rest_num == 2) {
            a_stage_.Tick();
            b_stage_.Tick();
            b_stage_.Tick();
        }
    }
 private:
    PipelineStage a_stage_;
    PipelineStage b_stage_;
    PipelineStage c_stage_;
};

} // namespace algo

#endif