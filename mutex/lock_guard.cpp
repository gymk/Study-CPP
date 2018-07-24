#include <iostream>
#include <mutex>

template <typename BASICLOCKABLE>
void ManualLockUnlock(BASICLOCKABLE & mut, std::string msg)
{
    mut.lock();
    std::cout << msg << "Manually locked, unlocked\n";

    if(mut.try_lock())
    {
        std::cout << msg << "able to try_lock after manual lock\n";
        mut.unlock();
    }
    else
    {
        std::cout << msg << "UNABLE to try_lock after manual lock\n";
    }
    mut.unlock();
    std::cout << std::endl;
}

template <typename BASICLOCKABLE>
void lock_guard(BASICLOCKABLE & mut, std::string msg)
{
    std::lock_guard<BASICLOCKABLE> lc(mut);
    std::cout << msg << "lock_guard locked, unlocked\n";

    if(mut.try_lock())
    {
        std::cout << msg << "able to try_lock again inside lock_guard\n";
        mut.unlock();
    }
    else
    {
        std::cout << msg << "UNABLE to try_lock again inside lock_guard\n";
    }
    {
        std::lock_guard<BASICLOCKABLE> lc2(mut);
        std::cout << msg << "SECOND LEVEL lock_guard locked, unlocked\n";
    }
    std::cout << std::endl;
}

template <typename BASICLOCKABLE>
void try_lock(BASICLOCKABLE & mut, std::string msg)
{
    mut.try_lock();
    std::cout << msg << "try_lock locked, unlocked\n";

    if(mut.try_lock())
    {
        std::cout << msg << "able to try_lock again inside try_lock\n";
        mut.unlock();
    }
    else
    {
        std::cout << msg << "UNABLE to try_lock again inside try_lock\n";
    }

    mut.unlock();
    std::cout << std::endl;
}

int main()
{
    std::string msg;
    
    std::mutex mut;
    msg = "std::mutex ";
    ManualLockUnlock(mut, msg);
    lock_guard(mut, msg);
    try_lock(mut, msg);

    std::recursive_mutex    recMut;
    msg = "std::recursive_mutex ";

    ManualLockUnlock(recMut, msg);
    lock_guard(recMut, msg);
    try_lock(recMut, msg);
}