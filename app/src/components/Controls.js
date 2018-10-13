import React, { Component } from 'react';
import styled from 'styled-components';
import { connect } from 'react-redux'
import { openControls, closeControls, motorOffAll } from '../actions/control';
import { controlsOpened } from '../selectors/app';
import MotorControl from './MotorControl';

export const HANDLE_HEIGHT = 48;
const MAX_CONTENT_HEIGHT = 340;
const ControlsWrapper = styled.div`
    background: white;
    position: absolute;
    width: 100%;
    transition: top ease-in 300ms;
    top: calc(100% - ${HANDLE_HEIGHT}px);
    ${props => props.isOpened && `
        top: calc(100% - ${MAX_CONTENT_HEIGHT}px);
    `}
`;
const ControlsContent = styled.div`
    transition: opacity ease-in 300ms;
    max-height: ${MAX_CONTENT_HEIGHT}px;
    opacity: 0;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    margin: 16px;
    ${props => props.isOpened && `
        opacity: 1;
    `}
`;
const HandleElement = styled.div`
    height: ${HANDLE_HEIGHT}px;
    display: flex;
    justify-content: center;
    align-items: center;
    cursor: pointer;
    box-shadow: 0px 5px 20px #d8d7d7;
`;

class Controls extends Component {
    handleOpen = () => this.props.open();
    handleClose = () => this.props.close();
    handleOffAll = () => this.props.offAll();

    render() {
        const { isOpened } = this.props;

        const title = isOpened ? "Close controls" : "Open controls";
        const handleClick = isOpened ? this.handleClose : this.handleOpen;

        return (
            <ControlsWrapper isOpened={isOpened}>
                <HandleElement onClick={handleClick}>
                    {title}
                </HandleElement>
                <ControlsContent isOpened={isOpened}>
                    <button onClick={this.handleOffAll}>{"Off all"}</button>
                    <MotorControl id="1" />
                    <MotorControl id="2" />
                    <MotorControl id="3" />
                    <MotorControl id="4" />
                    <MotorControl id="5" />
                    <MotorControl id="6" />
                </ControlsContent>
            </ControlsWrapper>
        );
    }
}

export default connect(
    state => ({
        isOpened: controlsOpened(state),
    }),
    dispatch => ({
        open: () => dispatch(openControls()),
        close: () => dispatch(closeControls()),
        offAll: () => dispatch(motorOffAll()),
    })
)(Controls);
