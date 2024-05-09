#pragma once

#include <memory>
#include "Protocol.hpp"
#include <iostream>

namespace CalCulateNS
{
    enum
    {
        Success = 0,
        DivZeroErr,
        ModZeroErr,
        Unknown
    };

    class Calculate
    {
    public:
        Calculate() {}

        shared_ptr<Protocol::Response> Cal(shared_ptr<Protocol::Request> req)
        {
            shared_ptr<Protocol::Response> resp = fact->BuildResponse();
            resp->SetCode(Success);
            switch (req->GetOper())
            {
                case '+':
                    resp->SetResult(req->GetX() + req->GetY());
                    break;
                case '-':
                    resp->SetResult(req->GetX() - req->GetY());
                    break;
                case '*':
                    resp->SetResult(req->GetX() * req->GetY());
                    break;
                case '/':
                {
                    if (req->GetY() == 0)
                    {
                        resp->SetCode(DivZeroErr);
                    }
                    else
                    {
                        resp->SetResult(req->GetX() / req->GetY());
                    }
                }
                break;
                case '%':
                {
                    if (req->GetY() == 0)
                    {
                        resp->SetCode(ModZeroErr);
                    }
                    else
                    {
                        resp->SetResult(req->GetX() % req->GetY());
                    }
                }
                break;
                default:
                    resp->SetCode(Unknown);
                break;
            }

            return resp;
        }

        ~Calculate() {}

    private:
        shared_ptr<Protocol::Factory> fact;
    };
}