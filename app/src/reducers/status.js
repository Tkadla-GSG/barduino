const SERVER_STATUS_RECEIVED = "SERVER_STATUS";

const status = (state = { isBrewing: false }, action) => {
    switch (action.type) {
        case SERVER_STATUS_RECEIVED:
            return ({
                ...state,
                ...action.payload,
            });
        default:
            return state
        }
    }

export default status;