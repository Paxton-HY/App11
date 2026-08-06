local board = {
    " ", " ", " ",
    " ", " ", " ",
    " ", " ", " "
}

local curr_player = "X"

function print_board()
    print("-------------------")
    for i = 1, 9, 3 do
        print(" " .. board[i] .. "|" .. board[i + 1] .. "|" .. board[i + 2])
        if i < 7 then
            print("--+--+--")
        end
    end
    print("-------------------")
end

-- print_board()

function check_win()
    local wins = {
        { 1, 2, 3 }, -- Row 1
        { 4, 5, 6 }, -- Row 2
        { 7, 8, 9 }, -- Row 3

        { 1, 4, 7 }, -- Column 1
        { 2, 5, 8 }, -- Column 2
        { 3, 6, 9 }, -- Column 3

        { 1, 5, 9 }, -- Main Diagonal
        { 3, 5, 7 }  -- Other Diagonal
    }

    for _, win in ipairs(wins) do
        local a, b, c = win[1], win[2], win[3]
        if board[a] == curr_player and board[b] == curr_player and board[c] == curr_player then
            return true
        end
    end
end

-- Checking Draw

function check_draw()
    for i = 1, 9 do
        if board[i] == " " then
            return false
        end
    end
    return true
end

function switch_player()
    if curr_player == "X" then
        curr_player = "O"
    else
        curr_player = "X"
    end
end

-- Main Game Loop

function play()
    while true do
        print_board()
        io.write("Player " .. curr_player .. ". Choose a Position b/w 1-9 :- ")
        local pos = tonumber(io.read())
        if pos and pos >= 1 and pos <= 9 and board[pos] == " " then
            board[pos] = curr_player
            if check_win() then
                print_board()
                print("Player " .. curr_player .. " Wins!")
                break
            elseif check_draw() then
                print_board()
                print("It is a Draw!")
                break
            else
                switch_player()
            end
        else
            print("\n\"Invalid Move. Try again!\"")
        end
    end
end

-- Start Game
play()
